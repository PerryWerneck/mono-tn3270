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
 * Este programa está nomeado como simple.cs e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

class test {

	[DllImport ("lib3270-mono")]
	extern static IntPtr tn3270_create_session(string name);

	[DllImport ("lib3270-mono")]
	extern static void tn3270_destroy_session(IntPtr session);

	[DllImport ("lib3270-mono")]
	extern static void tn3270_get_version(IntPtr session, StringBuilder str, int strlen);

	[DllImport ("lib3270-mono")]
	extern static void tn3270_get_revision(IntPtr session, StringBuilder str, int strlen);

	static void Main(string[] args) {

		IntPtr handle = tn3270_create_session("");

		StringBuilder str = new StringBuilder(100);
		tn3270_get_version(handle, str, 100);
		System.Console.WriteLine(str);

		tn3270_get_revision(handle, str, 100);
		System.Console.WriteLine(str);

		tn3270_destroy_session(handle);

    }
}
