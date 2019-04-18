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
 * Este programa está nomeado como get.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include "private.h"


/*---[ Implement ]----------------------------------------------------------------------------------*/

 /**
  * @brief Obtém a versão da biblioteca.
  *
  */
 int tn3270_get_version(h3270::session *ses, char* str, int strlen) {

 	if(!ses) {
		return -1;
 	}

 	try {
		strncpy(str,ses->get_version().c_str(),strlen);
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 		return -1;
 	}
 	return 0;
 }

 /**
  * @brief Obtém a revisão da biblioteca.
  *
  */
 int tn3270_get_revision(h3270::session *ses, char* str, int strlen) {

 	if(!ses) {
		return -1;
 	}

 	try {
		strncpy(str,ses->get_revision().c_str(),strlen);
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 		return -1;
 	}
 	return 0;
 }

 int tn3270_get_cstate(h3270::session *ses) {

 	if(!ses) {
		return -1;
 	}

 	trace_to_file("%s: %d",__FUNCTION__,(int) ses->get_cstate());

	try {
		return (int) ses->get_cstate();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_program_message(h3270::session *ses) {

 	if(!ses) {
		return -1;
 	}

	try {
		return (int) ses->get_program_message();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_secure(h3270::session *ses) {

 	if(!ses) {
		return -1;
 	}

	try {
		return (int) ses->get_secure();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_width(h3270::session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->get_width();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_height(h3270::session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->get_height();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_length(h3270::session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->get_length();
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_cursor_addr(h3270::session *ses) {

	if(ses) {

		try {
			return (int) ses->get_cursor_addr();
		} catch(std::exception &e) {
			tn3270_lasterror = e.what();
		}

	}
	return -1;

 }

 int tn3270_get_url(h3270::session *ses, char* str, int strlen) {

	if(ses) {

		try {

			strncpy(str,ses->get_url().c_str(),strlen);
			return 0;

		} catch(std::exception &e) {
			tn3270_lasterror = e.what();
		}

	}
	return -1;

 }

 int tn3270_get_error_message(h3270::session *ses, char* str, int strlen) {

	strncpy(str,tn3270_lasterror.c_str(),strlen);
	return 0;

 }
