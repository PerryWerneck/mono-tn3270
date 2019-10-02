'
' "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
' (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
' aplicativos mainframe. Registro no INPI sob o nome G3270.
'
' Copyright (C) <2008> <Banco do Brasil S.A.>
'
' Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
' os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
' Free Software Foundation.
'
' Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
' GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
' A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
' obter mais detalhes.
'
' Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
' programa; se não, escreva para a Free Software Foundation, Inc., 51 Franklin
' St, Fifth Floor, Boston, MA  02110-1301  USA
'
' Este programa está nomeado como vbclass.vb e possui - linhas de código.
'
' Contatos:
'
' perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
' erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
'

Imports System
Imports System.Text
Imports System.Runtime.InteropServices

Public Class pw3270

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_create_session(ByVal Name As String) As IntPtr
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_destroy_session(ByVal hSession As IntPtr) as Long
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_version(ByVal hSession As IntPtr, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_revision(ByVal hSession As IntPtr, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_connect(ByVal hSession As IntPtr, ByVal buffer As String, ByVal seconds as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_is_connected(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_disconnect(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_wait_for_ready(ByVal hSession As IntPtr, ByVal seconds as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_wait(ByVal hSession As IntPtr, ByVal seconds as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_cstate(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_program_message(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_secure(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_string(ByVal hSession As IntPtr, ByVal addr as Integer, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_get_string_at(ByVal hSession As IntPtr, ByVal row as Integer, ByVal col as Integer, ByVal buffer As StringBuilder, ByVal strlen as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_set_string_at(ByVal hSession As IntPtr, ByVal row as Integer, ByVal col as Integer, ByVal buffer As String) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_wait_for_string_at(ByVal hSession As IntPtr, ByVal row as Integer, ByVal col as Integer, ByVal key As String, ByVal timeout as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_cmp_string_at(ByVal hSession As IntPtr, ByVal row as Integer, ByVal col as Integer, ByVal buffer As String) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_set_unlock_delay(ByVal hSession As IntPtr, ByVal ms as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_set_cursor_position(ByVal hSession As IntPtr, ByVal row as Integer, ByVal col as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_set_cursor_addr(ByVal hSession As IntPtr, ByVal addr as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_enter(ByVal hSession As IntPtr) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_pfkey(ByVal hSession As IntPtr, ByVal key as Integer) as Integer
	End Function

	<DllImport("mono-tn3270", CallingConvention := CallingConvention.Cdecl)> _
	Private Shared Function tn3270_pakey(ByVal hSession As IntPtr, ByVal key as Integer) as Integer
	End Function

	Private Shared hSession As IntPtr

	Public Sub New(ByVal name as String)
		hSession = tn3270_create_session(name)
	End Sub

	Public Sub Connect(ByRef url as String, ByVal seconds as Integer)
		tn3270_connect(hSession, url, seconds)
	End Sub

	Public Sub Disconnect()
		tn3270_disconnect(hSession)
	End Sub

	Public Sub Finalize()
		tn3270_destroy_session(hSession)
	End Sub

	Public ReadOnly Property Version As String
		Get
			dim buffer As New StringBuilder(1024)
			tn3270_get_version(hSession, buffer, 1024)
			return buffer.toString
		End Get
	End Property

	Public ReadOnly Property Revision As String
		Get
			dim buffer As New StringBuilder(1024)
			tn3270_get_revision(hSession, buffer, 1024)
			return buffer.toString
		End Get
	End Property

	Public ReadOnly Property Connected As Boolean
		Get
			return tn3270_is_connected(hSession)
		End Get
	End Property

	Public Function GetStringAt(ByVal row as Integer, ByVal col as Integer, ByVal strlen as Integer)
		dim buffer As New StringBuilder(strlen)
		tn3270_get_string_at(hSession, row, col, buffer, strlen)
		return buffer.toString
	End Function

	Public Sub WaitForReady(ByVal seconds as Integer)
		tn3270_wait_for_ready(hSession, seconds)
	End Sub


End Class


Public Module modmain

	Sub Main()

		dim host as new pw3270("")

		Console.WriteLine("Using pw3270 version " + host.Version + " revision " + host.Revision)

		host.Connect("tn3270://zos.efglobe.com:telnet",10)

		if host.Connected Then

			Console.WriteLine(host.GetStringAt(14,19,38))

			host.Disconnect()
		End If

	End Sub


End Module
