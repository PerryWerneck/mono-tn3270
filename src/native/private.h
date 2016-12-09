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
#ifndef PRIVATE_H_INCLUDED

	#define PRIVATE_H_INCLUDED

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

	#ifdef DEBUG
		#define debug( fmt, ... )	fprintf(stderr, "%s(%d) " fmt "\n" , __FILE__, (int) __LINE__, __VA_ARGS__ ); fflush(stderr);
	#else
		#define debug( fmt, ... )	/* */
	#endif // DEBUG

	#include <pw3270cpp.h>
	#include <cerrno>
	#include <cstring>

	extern "C" {

 		DLL_PUBLIC h3270::session * tn3270_create_session(const char *name);

		DLL_PUBLIC void tn3270_destroy_session(h3270::session *ses);

		DLL_PUBLIC void tn3270_get_version(h3270::session *ses, char* str, int strlen);
		DLL_PUBLIC void tn3270_get_revision(h3270::session *ses, char* str, int strlen);

		DLL_PUBLIC int tn3270_connect(h3270::session *ses, const char *host, time_t wait);
		DLL_PUBLIC int tn3270_disconnect(h3270::session *ses);
		DLL_PUBLIC int tn3270_is_connected(h3270::session *ses);

		DLL_PUBLIC int tn3270_wait_for_ready(h3270::session *ses, int seconds);
		DLL_PUBLIC int tn3270_wait(h3270::session *ses, int seconds);

		DLL_PUBLIC int tn3270_get_cstate(h3270::session *ses);
		DLL_PUBLIC int tn3270_get_program_message(h3270::session *ses);
		DLL_PUBLIC int tn3270_get_secure(h3270::session *ses);

		DLL_PUBLIC void tn3270_get_string(h3270::session *ses, int addr, char* str, int strlen);
		DLL_PUBLIC void tn3270_get_string_at(h3270::session *ses, int row, int col, char* str, int strlen);

		DLL_PUBLIC void tn3270_set_string_at(h3270::session *ses, int row, int col, const char* str);

		DLL_PUBLIC int tn3270_wait_for_string_at(h3270::session *ses, int row, int col, const char *key, int timeout);
		DLL_PUBLIC int tn3270_cmp_string_at(h3270::session *ses, int row, int col, const char* str);

		DLL_PUBLIC void tn3270_set_unlock_delay(h3270::session *ses, int ms);
		DLL_PUBLIC void tn3270_set_cursor_position(h3270::session *ses, int row, int col);
 		DLL_PUBLIC void tn3270_set_cursor_addr(h3270::session *ses, int addr);

		DLL_PUBLIC int tn3270_enter(h3270::session *ses);
		DLL_PUBLIC int tn3270_pfkey(h3270::session *ses, int key);
		DLL_PUBLIC int tn3270_pakey(h3270::session *ses, int key);

	}


#endif // PRIVATE_H_INCLUDED
