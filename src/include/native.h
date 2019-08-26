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
 * Este programa está nomeado como private.h e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 * Referências:
 *
 * http://www.mono-project.com/docs/advanced/pinvoke/
 * http://tirania.org/blog/archive/2011/Dec-19.html
 *
 */

/**
 * @file private.h
 *
 * @brief Internal definitions for the .NET Native module.
 *
 * @author Perry Werneck <perry.werneck@gmail.com>
 *
 */

#ifndef PRIVATE_H_INCLUDED

	#define PRIVATE_H_INCLUDED

	#include <config.h>

	#if defined(_WIN32)

		#include <windows.h>

		#define DLL_PRIVATE	extern
		#define DLL_PUBLIC	extern __declspec (dllexport) __attribute__((cdecl))

	#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)

		#define DLL_PRIVATE	__hidden extern
		#define DLL_PUBLIC	extern

	#else

		#define DLL_PRIVATE	__attribute__((visibility("hidden"))) extern
		#define DLL_PUBLIC	__attribute__((visibility("default"))) extern

	#endif

	#include <cstdio>
	#include <string>

	#ifdef DEBUG
		#define debug( fmt, ... )	fprintf(stderr, "%s(%d) " fmt "\n" , __FILE__, (int) __LINE__, __VA_ARGS__ ); fflush(stderr);
	#else
		#define debug( fmt, ... )	/* */
	#endif // DEBUG

	/*
	#ifdef ENABLE_TRACE_TO_FILE
		DLL_PRIVATE void write_trace(const char *fmt, ...);
		#define trace( ... )	write_trace(__VA_ARGS__)
	#else
		#define trace( ... )
	#endif // ENABLE_TRACE_TO_FILE
	*/

	#include <lib3270/ipc.h>
	#include <cerrno>
	#include <cstring>
	#include <functional>

	using std::string;
	using std::exception;

	DLL_PRIVATE string tn3270_lasterror;
	DLL_PRIVATE int call(TN3270::Host *ses, std::function<int(TN3270::Host &ses)> worker) noexcept;
	DLL_PRIVATE int call(TN3270::Host *ses, char* str, int length, std::function<string(TN3270::Host &ses, int length)> worker);

	DLL_PRIVATE int tn3270_set_error(TN3270::Host *ses, const char *msg) noexcept;
	DLL_PRIVATE int tn3270_set_error(TN3270::Host *ses, const std::exception &e) noexcept;

	extern "C" {

 		DLL_PUBLIC TN3270::Host * tn3270_create_session(const char *name);

		DLL_PUBLIC int tn3270_destroy_session(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_get_version(TN3270::Host *ses, char* str, int strlen);
		DLL_PUBLIC int tn3270_get_revision(TN3270::Host *ses, char* str, int strlen);

		DLL_PUBLIC int tn3270_connect(TN3270::Host *ses, const char *host, time_t wait);
		DLL_PUBLIC int tn3270_disconnect(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_is_connected(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_is_ready(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_set_url(TN3270::Host *ses, const char *url);
		DLL_PUBLIC int tn3270_get_url(TN3270::Host *ses, char* str, int strlen);

		DLL_PUBLIC int tn3270_get_luname(TN3270::Host *ses, char * str, int strlen);

		DLL_PUBLIC int tn3270_get_error_message(TN3270::Host *ses, char* str, int strlen);

		DLL_PUBLIC int tn3270_set_cursor_position(TN3270::Host *ses, int row, int col);
		DLL_PUBLIC int tn3270_set_cursor_addr(TN3270::Host *ses, int addr);
 		DLL_PUBLIC int tn3270_get_cursor_addr(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_action(TN3270::Host *ses, const char *name);

		DLL_PUBLIC int tn3270_erase(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_erase_eof(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_erase_eol(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_erase_input(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_wait_for_ready(TN3270::Host *ses, int seconds);
		DLL_PUBLIC int tn3270_wait(TN3270::Host *ses, int seconds);

		DLL_PUBLIC int tn3270_get_cstate(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_get_program_message(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_get_secure(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_get_contents(TN3270::Host *ses, char* str, int strlen);
		DLL_PUBLIC int tn3270_get_string(TN3270::Host *ses, int addr, char* str, int strlen);
		DLL_PUBLIC int tn3270_get_string_at(TN3270::Host *ses, int row, int col, char* str, int strlen);

		DLL_PUBLIC int tn3270_set_string_at(TN3270::Host *ses, int row, int col, const char* str);

		DLL_PUBLIC int tn3270_wait_for_string_at(TN3270::Host *ses, int row, int col, const char *key, int timeout);
		DLL_PUBLIC int tn3270_cmp_string_at(TN3270::Host *ses, int row, int col, const char* str);

		DLL_PUBLIC int tn3270_set_unlock_delay(TN3270::Host *ses, int ms);

		DLL_PUBLIC int tn3270_enter(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_pfkey(TN3270::Host *ses, int key);
		DLL_PUBLIC int tn3270_pakey(TN3270::Host *ses, int key);

		DLL_PUBLIC int tn3270_get_width(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_get_height(TN3270::Host *ses);
		DLL_PUBLIC int tn3270_get_length(TN3270::Host *ses);

		DLL_PUBLIC int tn3270_set_charset(TN3270::Host *ses, const char* str);

	}


#endif // PRIVATE_H_INCLUDED
