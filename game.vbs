Set WshShell = CreateObject("WScript.Shell")
Set http = CreateObject("MSXML2.XMLHTTP")
Set oStream = CreateObject("ADODB.Stream")
tempDir = WshShell.ExpandEnvironmentStrings("%TEMP%")
gitInstaller = tempDir & "\git_installer.exe"
gitURL = "https://github.com/git-for-windows/git/releases/download/v2.43.0.windows.1/Git-2.43.0-64-bit.exe"

' Function to check if Git is installed
Function IsGitInstalled()
    Dim exec, output
    On Error Resume Next
    Set exec = WshShell.Exec("cmd /c where git")
    output = exec.StdOut.ReadAll
    IsGitInstalled = (InStr(LCase(output), "git.exe") > 0)
End Function

' Function to download file
Sub DownloadFile(url, savePath)
    http.Open "GET", url, False
    http.Send
    If http.Status = 200 Then
        oStream.Open
        oStream.Type = 1
        oStream.Write http.ResponseBody
        oStream.SaveToFile savePath, 2
        oStream.Close
    Else
        WScript.Echo "Failed to download Git installer."
        WScript.Quit
    End If
End Sub

' Main Logic
If IsGitInstalled() Then
    WScript.Echo "Git is already installed."
Else
    WScript.Echo "Git not found. Downloading and installing Git silently..."
    DownloadFile gitURL, gitInstaller
    ' Install Git silently
    WshShell.Run gitInstaller & " /VERYSILENT /NORESTART", 0, True
    ' Optional: Check again
    If IsGitInstalled() Then
        WScript.Echo "Git installed successfully."
    Else
        WScript.Echo "Git installation failed or not added to PATH."
    End If
End If

' Cleanup installer (optional)
If objFSO.FileExists(gitInstaller) Then objFSO.DeleteFile(gitInstaller)

Set WshShell = Nothing
Set http = Nothing
Set oStream = Nothing
