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

	Private Shared hSession As IntPtr

	Public Sub New(ByVal name as String)
		hSession = tn3270_create_session(name)
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



End Class


Public Module modmain

	Sub Main()

		dim host as new pw3270("")

		Console.WriteLine ("Using pw3270 version " + host.Version + " revision " + host.Revision)


	End Sub


End Module
