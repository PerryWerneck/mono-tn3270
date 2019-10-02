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
 * Este programa está nomeado como tn3270-sharp.cs e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 * Referências:
 *
 * https://msdn.microsoft.com/en-us/library/5ast78ax.aspx
 *
 */

using System;
using System.Text;
using System.Runtime.InteropServices;

namespace tn3270 {

	/// <summary>
	/// Session with 3270 HOST.
	/// </summary>
	public class Session {

		/// <summary>
		/// lib3270 session handle
		/// </summary>
		private IntPtr hSession;

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static IntPtr tn3270_create_session(string name);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_destroy_session(IntPtr session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_version(IntPtr session, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_revision(IntPtr session, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_connect(IntPtr Session, string host, int wait);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_is_connected(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_is_ready(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_disconnect(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_wait_for_ready(IntPtr Session, int seconds);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_wait(IntPtr Session, int seconds);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_cstate(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_program_message(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_secure(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_contents(IntPtr Session, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_string(IntPtr Session, int addr, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_string_at(IntPtr Session, int row, int col, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_string_at(IntPtr Session, int row, int col, string str);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_wait_for_string_at(IntPtr Session, int row, int col, string key, int timeout);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_cmp_string_at(IntPtr Session, int row, int col, string str);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_unlock_delay(IntPtr Session, int ms);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_cursor_position(IntPtr Session, int row, int col);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
 		extern static int tn3270_set_cursor_addr(IntPtr Session, int addr);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
 		extern static int tn3270_get_cursor_addr(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_enter(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_pfkey(IntPtr Session, int key);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_pakey(IntPtr Session, int key);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_width(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_height(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_length(IntPtr Session);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_charset(IntPtr Session, string str);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_url(IntPtr Session, string str);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_url(IntPtr Session, StringBuilder str, int strlen);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_set_error_message(IntPtr Session, string str);

		[DllImport ("lib3270-mono",CallingConvention=CallingConvention.Cdecl)]
		extern static int tn3270_get_error_message(IntPtr Session, StringBuilder str, int strlen);

		/// <summary>
		/// Create a new session with lib3270/pw3270
		/// </summary>
		///
		/// <param name="name">Session name or empty string for a hidden session</param>
		///
		public Session(string name) {
			hSession = tn3270_create_session(name);
			tn3270_set_charset(hSession,"UTF-8");
		}

		/// <summary>
		/// Disconnect from host, destroy session.
		/// </summary>
		///
		~Session() {
			tn3270_destroy_session(hSession);
		}

		/// <summary>
		/// Get lib3270/pw3270 Version identifier
		/// </summary>
		///
		/// <returns>
		/// The version of the active instance.
		/// </returns>
		///
		public string GetVersion() {
			StringBuilder str = new StringBuilder(10);
			tn3270_get_version(hSession, str, 10);
			return str.ToString();
		}

		/// <summary>
		/// Lib3270 version.
		/// </summary>
		///
		/// <returns>
		/// Lib3270 version string
		/// </returns>
		///
		public string Version {
			get {
				return GetVersion();
			}
		}

		/// <summary>
		/// Get lib3270/pw3270 Revision number
		/// </summary>
		///
		/// <returns>
		/// The revision of the active instance.
		/// </returns>
		///
		public string GetRevision() {
			StringBuilder str = new StringBuilder(10);
			tn3270_get_revision(hSession, str, 10);
			return str.ToString();
		}

		public string Revision {
			get {
				return GetRevision();
			}
		}

		/// <summary>
		/// Connect to 3270 host.
		/// </summary>
		///
		/// <param name="host">URL of the target host (tn3270://hostname:port)</param>
		/// <param name="wait">How many seconds should the call wait for the connection becomes ready</param>
		///
		/// <returns>
		/// </returns>
		///
		public int Connect(string host, int wait) {
			return tn3270_connect(hSession, host, wait);
		}

		/// <summary>
		/// Get connection state
		/// </summary>
		///
		/// <returns>
		/// true if the session is connected to a remote host.
		/// </returns>
		///
		public bool IsConnected() {
			return tn3270_is_connected(hSession) != 0;
		}

		public bool Connected {
			get {
				return tn3270_is_connected(hSession) != 0;
			}
		}

		public bool IsReady() {
			return tn3270_is_ready(hSession) != 0;
		}

		public bool Ready {
			get {
				return tn3270_is_ready(hSession) != 0;
			}
		}

		/// <summary>
		/// Disconnect from 3270 host.
		/// </summary>
		///
		public int Disconnect() {
			return tn3270_disconnect(hSession);
		}

		/// <summary>
		/// Wait for network activity
		/// </summary>
		///
		/// <param name="seconds">Seconds to wait</param>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int WaitForReady(int seconds) {
			return tn3270_wait_for_ready(hSession, seconds);
		}

		/// <summary>
		/// "Sleep" keeping the network activity.
		/// </summary>
		///
		/// <param name="seconds">Number of seconds to wait</param>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int Wait(int seconds) {
			return tn3270_wait(hSession, seconds);
		}

		/// <summary>
		/// Get contents
		/// </summary>
		///
		/// <returns>
		/// Contents from terminal screen.
		/// </returns>
		///
		public override string ToString() {
			int strlen = (tn3270_get_width(hSession)+1) * (tn3270_get_height(hSession)+1);
			StringBuilder str = new StringBuilder(strlen+1);
			strlen = tn3270_get_contents(hSession, str, strlen);
			return str.ToString();
		}


		/// <summary>
		/// Get contents at address
		/// </summary>
		///
		/// <param name="addr">Address of text in the screen buffer</param>
		/// <param name="strlen">Number of characters to get</param>
		///
		/// <returns>
		/// Contents from terminal screen.
		/// </returns>
		///
		public string GetString(int addr, int strlen) {
			StringBuilder str = new StringBuilder(strlen+1);
			tn3270_get_string(hSession, addr, str, strlen);
			return str.ToString();
		}

		/// <summary>
		/// Get contents at position.
		/// </summary>
		///
		/// <param name="row">Start row</param>
		/// <param name="col">Start col</param>
		/// <param name="strlen">Number of characters to get</param>
		///
		/// <returns>
		/// Contents from terminal screen.
		/// </returns>
		///
		public string GetStringAt(int row, int col, int strlen) {
			StringBuilder str = new StringBuilder(strlen+1);
			tn3270_get_string_at(hSession, row, col, str, strlen);
			return str.ToString();
		}

		/// <summary>
		/// Set contents at position
		/// </summary>
		///
		/// <param name="row">Start row</param>
		/// <param name="col">Start col</param>
		/// <param name="str">Text to set</param>
		///
		public void SetStringAt(int row, int col, string str) {
			tn3270_set_string_at(hSession, row, col, str);
		}

		/// <summary>
		/// Wait for text at position.
		/// </summary>
		///
		/// <param name="row">Start row</param>
		/// <param name="col">Start col</param>
		/// <param name="str">Text to wait</param>
		/// <param name="timeout">Seconds to wait</param>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int WaitForStringAt(int row, int col, string str, int timeout) {
			return tn3270_wait_for_string_at(hSession, row, col, str, timeout);
		}

		/// <summary>
		/// Compare contents at position
		/// </summary>
		///
		/// <param name="row">Start row</param>
		/// <param name="col">Start col</param>
		/// <param name="str">Text to compare</param>
		///
		/// <returns>
		/// Result (0 = The strings are the same).
		/// </returns>
		///
		public int CmpStringAt(int row, int col, string str) {
			return tn3270_cmp_string_at(hSession, row, col, str);
		}

		/// <summary>
		/// Set cursor position.
		/// </summary>
		///
		/// <param name="row">New cursor row</param>
		/// <param name="col">New cursor column</param>
		///
		public void SetCursorPosition(int row, int col) {
			tn3270_set_cursor_position(hSession, row, col);
		}

		/// <summary>
		/// Set cursor position based on address.
		/// </summary>
		///
		/// <param name="addr">Address of the new cursor position</param>
		///
		public void SetCursorPosition(int addr) {
			tn3270_set_cursor_addr(hSession, addr);
		}

		/// <summary>
		/// Get cursor address
		/// </summary>
		///
		public int GetCursorPosition() {
			return tn3270_get_cursor_addr(hSession);
		}

		/// <summary>
		/// Cursor address
		/// </summary>
		///
		public int CursorPosition {
			set {
				tn3270_set_cursor_addr(hSession, value);
			}
			get {
				return tn3270_get_cursor_addr(hSession);
			}
		}

		/// <summary>
		/// Set the "screen ready" delay
		/// </summary>
		///
		public int SetUnlockDelay(int ms) {
			return tn3270_set_unlock_delay(hSession, ms);
		}

		/// <summary>
		/// Set the "screen ready" delay
		/// </summary>
		///
		public int UnlockDelay {
			set {
				tn3270_set_unlock_delay(hSession, value);
			}
		}


		/// <summary>
		/// Send "Enter" key
		/// </summary>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int Enter() {
			return tn3270_enter(hSession);
		}

		/// <summary>
		/// Send "PF" key
		/// </summary>
		///
		/// <param name="key">Key identifier 1=PF1, 2=PF2, ...</param>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int PfKey(int key) {
			return tn3270_pfkey(hSession, key);
		}

		/// <summary>
		/// Send "PA" key
		/// </summary>
		///
		/// <param name="key">Key identifier 1=PA1, 2=PA2, ...</param>
		///
		/// <returns>
		///
		/// </returns>
		///
		public int PaKey(int key) {
			return tn3270_pakey(hSession, key);
		}

		/// <summary>
		/// Get screen width
		/// </summary>
		///
		/// <returns>
		/// Screen width in characters (negative on error)
		/// </returns>
		///
		public int GetWidth() {
			return tn3270_get_width(hSession);
		}

		/// <summary>
		/// Screen width in characters
		/// </summary>
		///
		/// <returns>
		/// Screen width in characters (negative on error)
		/// </returns>
		///
		public int Width {
			get {
				return tn3270_get_width(hSession);
			}
		}

		/// <summary>
		/// Get screen height
		/// </summary>
		///
		/// <returns>
		/// Screen width in characters (negative on error)
		/// </returns>
		///
		public int GetHeight() {
			return tn3270_get_height(hSession);
		}

		/// <summary>
		/// Screen height in characters
		/// </summary>
		///
		/// <returns>
		/// Screen height in characters (negative on error)
		/// </returns>
		///
		public int Height {
			get {
				return tn3270_get_height(hSession);
			}
		}

		/// <summary>
		/// Get length of terminal buffer (width * height)
		/// </summary>
		///
		/// <returns>
		/// Terminal length in characters (negative on error)
		/// </returns>
		///
		public int GetLength() {
			return tn3270_get_length(hSession);
		}

		/// <summary>
		/// Length of terminal buffer (width * height)
		/// </summary>
		///
		/// <returns>
		/// Terminal length in characters (negative on error)
		/// </returns>
		///
		public int Length {
			get {
				return tn3270_get_length(hSession);
			}
		}

		public string CharSet {
			set {
				tn3270_set_charset(hSession,value);
			}
		}

		/// <summary>
		/// 3270 host URL
		/// </summary>
		///
		/// <returns>
		/// 3270 host URL
		/// </returns>
		///
		public string Url {
			set {
				tn3270_set_url(hSession,value);
			}
			get {
				StringBuilder str = new StringBuilder(1025);
				tn3270_get_url(hSession, str, 1024);
				return str.ToString();
			}
		}

		/// <summary>
		/// Last lib3270 error message
		/// </summary>
		///
		/// <returns>
		/// Last lib3270 error message
		/// </returns>
		///
		public string Error {
			set {
				tn3270_set_error_message(hSession,value);
			}
			get {
				StringBuilder str = new StringBuilder(1025);
				tn3270_get_error_message(hSession, str, 1024);
				return str.ToString();
			}
		}

	}

}
