/*
 * "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
 * (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
 * aplicativos mainframe. Registro no INPI sob o nome G3270.
 *
 * Copyright (C) <2008> <Banco do Brasil S.A.>
 *
 * Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
 * os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
 * Free Software Foundation.
 *
 * Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
 * GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
 * A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
 * obter mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
 * programa; se não, escreva para a Free Software Foundation, Inc., 51 Franklin
 * St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Este programa está nomeado como sample.cs e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

using tn3270;

class ipc {

	static void Main(string[] args) {

		tn3270.Session host = new tn3270.Session(":A");

		System.Console.WriteLine("Using tn3270 version " + host.Version + " revision " + host.Revision);
		System.Console.WriteLine("Screen size is " + host.Width + "x" + host.Height + " (" + host.Length + ")");

		// host.CharSet = "ISO-8859-1";

		if(host.Connected) {

			System.Console.WriteLine("Connected to " + host.Url);
			System.Console.WriteLine("Wait for ready returned " + host.WaitForReady(5));

			// System.Console.WriteLine(host.GetStringAt(1,1,1920));
			System.Console.WriteLine(host.GetString(1,1920));
			// System.Console.WriteLine(host);

		} else {

			System.Console.WriteLine("Host is disconnected");

		}

		System.Console.WriteLine("Error: " + host.Error);


	}

}
