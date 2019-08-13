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
 int tn3270_get_version(TN3270::Session *ses, char* str, int strlen) {

 	if(!ses) {
		return -1;
 	}

 	try {

		strncpy(str,ses->getVersion().c_str(),strlen);

 	} catch(const exception &e) {

 		tn3270_lasterror = e.what();
 		return -1;

 	}
 	return 0;
 }

 /**
  * @brief Obtém a revisão da biblioteca.
  *
  */
 int tn3270_get_revision(TN3270::Session *ses, char* str, int strlen) {

 	if(!ses) {
		return -1;
 	}

 	try {

		strncpy(str,ses->getRevision().c_str(),strlen);

 	} catch(const exception &e) {

 		tn3270_lasterror = e.what();
 		return -1;

 	}
 	return 0;
 }

 int tn3270_get_cstate(TN3270::Session *ses) {

 	if(!ses) {
		return -1;
 	}

	try {

		return (int) ses->getConnectionState();

 	} catch(const exception &e) {

 		tn3270_lasterror = e.what();

 	}
	return -1;

 }

 int tn3270_get_program_message(TN3270::Session *ses) {

 	if(!ses) {
		return -1;
 	}

	try {

		return (int) ses->getProgramMessage();

 	} catch(const exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_secure(TN3270::Session *ses) {

	/*
 	if(!ses) {
		return -1;
 	}

	try {

		return (int) ses->get_secure();

 	} catch(const exception &e) {
 		tn3270_lasterror = e.what();
 	}
 	*/

	return -1;

 }

 int tn3270_get_width(TN3270::Session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->getScreenWidth();
 	} catch(const exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_height(TN3270::Session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->getScreenHeight();
 	} catch(const exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_length(TN3270::Session *ses) {

 	if(!ses) {
		return 0;
 	}

	try {
		return (int) ses->getScreenLength();
 	} catch(const exception &e) {
 		tn3270_lasterror = e.what();
 	}
	return -1;

 }

 int tn3270_get_cursor_addr(TN3270::Session *ses) {

	if(ses) {

		try {
			return (int) ses->getCursorAddress();
		} catch(const exception &e) {
			tn3270_lasterror = e.what();
		}

	}
	return -1;

 }

 int tn3270_get_url(TN3270::Session *ses, char* str, int strlen) {

	if(ses) {

		try {

			strncpy(str,ses->getHostURL().c_str(),strlen);
			return 0;

		} catch(const exception &e) {
			tn3270_lasterror = e.what();
		}

	}
	return -1;

 }

 int tn3270_get_error_message(TN3270::Session *ses, char* str, int strlen) {

	strncpy(str,tn3270_lasterror.c_str(),strlen);
	return 0;

 }
