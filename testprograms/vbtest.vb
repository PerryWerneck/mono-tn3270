
Imports System
Imports System.Text
Imports System.Runtime.InteropServices

' This module houses the application's entry point.
Public Module modmain


	<DllImport("lib3270-mono")> _
	Private Shared Function tn3270_create_session(ByVal Name As String) As IntPtr
	End Function

	<DllImport("lib3270-mono")> _
	Private Shared Function tn3270_destroy_session(ByVal hSession As IntPtr) as Long
	End Function

	<DllImport("lib3270-mono")> _
	Private Shared Function tn3270_get_version(ByVal hSession As IntPtr, ByRef buffer As StringBuilder, ByVal strlen as Integer) as Long
	End Function

	' Main is the application's entry point.
	Sub Main()

		dim host as IntPtr = tn3270_create_session("")

		' Write text to the console.
		Console.WriteLine ("Hello World using Visual Basic!")



	End Sub

End Module

