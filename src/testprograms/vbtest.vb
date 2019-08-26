
Imports System
Imports System.Text
Imports System.Runtime.InteropServices

' This module houses the application's entry point.
Public Module modmain


	<DllImport("lib3270-mono", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_create_session(ByVal Name As String) As IntPtr
	End Function

	<DllImport("lib3270-mono", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_destroy_session(ByVal hSession As IntPtr) as Long
	End Function

	<DllImport("lib3270-mono", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_version(ByVal hSession As IntPtr, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Long
	End Function

	<DllImport("lib3270-mono", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_revision(ByVal hSession As IntPtr, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Long
	End Function

	' Application's entry point.
	Sub Main()

		dim host as IntPtr = tn3270_create_session("")
		dim buffer As New StringBuilder(1024)

		' Get library version
		tn3270_get_version(host, buffer, 1024)
		dim vrs as String = buffer.toString

		' Get Library revision
		tn3270_get_revision(host, buffer, 1024)
		dim rev as String = buffer.toString

		' Write text to the console.
		Console.WriteLine ("Using pw3270 version " + vrs + " revision " + rev)



		tn3270_destroy_session(host)

	End Sub

End Module
