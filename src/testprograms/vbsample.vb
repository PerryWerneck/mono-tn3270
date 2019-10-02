'
'  "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
'  (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
'  aplicativos mainframe. Registro no INPI sob o nome G3270.
'
'  Copyright (C) <2008> <Banco do Brasil S.A.>
'
'  Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
'  os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
'  Free Software Foundation.
'
'  Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
'  GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
'  A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
'  obter mais detalhes.
'
'  Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
'  programa; se não, escreva para a Free Software Foundation, Inc., 51 Franklin
'  St, Fifth Floor, Boston, MA  02110-1301  USA
'
'  Este programa está nomeado como vbsample.vb e possui - linhas de código.
'
'  Contatos:
'
'  perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
'  erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
'

Imports System

' This module houses the application's entry point.
Public Module modmain

	' Application's entry point.
	Sub Main()

		dim host as new tn3270.Session("")

		Console.WriteLine("Using pw3270 version " + host.getVersion() + " revision " + host.GetRevision())
		Console.WriteLine("Screen size is " + host.GetWidth() + "x" + host.GetHeigth())

		host.Connect("tn3270://zos.efglobe.com:telnet",10)

		if host.IsConnected() then

			Console.WriteLine("Connected to host")

			Console.WriteLine(host.GetStringAt(14,19,38))

			host.Disconnect()
			
		End If

	End Sub

End Module
