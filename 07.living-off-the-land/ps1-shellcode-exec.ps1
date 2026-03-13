#!/usr/bin/env -S powershell.exe -executionpolicy bypass

$code = @"
using System;
using System.Runtime.InteropServices;

public static class Win32 {
    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    public static extern int MessageBoxW(IntPtr hWnd, string text, string caption, uint type);

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool CloseHandle(IntPtr hObject);
}
"@

Add-Type -TypeDefinition $code -Language CSharp
[Win32]::MessageBoxW([IntPtr]::Zero, "PowerShell hello, world", "WSL2'able Interop", 0)
