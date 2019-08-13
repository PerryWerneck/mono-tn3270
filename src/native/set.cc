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
 * Este programa está nomeado como set.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include "private.h"

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_set_unlock_delay(TN3270::Session *ses, int ms) {
	try {
		ses->setUnlockDelay((unsigned short) ms);
	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return 0;
}

int tn3270_set_cursor_position(TN3270::Session *ses, int row, int col) {
	try {
		ses->setCursor((unsigned short) row, (unsigned short) col);
	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return 0;
}

int tn3270_set_cursor_addr(TN3270::Session *ses, int addr) {
	try {
		ses->setCursor((unsigned short) addr);
	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return 0;
}

int tn3270_set_charset(TN3270::Session *ses, const char* str) {

	try {

		ses->setCharSet(str);

	} catch(const exception &e) {

		tn3270_lasterror = e.what();
		return -1;

	}

	return 0;

}

int tn3270_set_url(TN3270::Session *ses, const char *url) {

	try {

		ses->setHostURL(url);

	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}

	return 0;
}

int tn3270_set_error_message(TN3270::Session *ses, const char *str) {
	tn3270_lasterror = str;
	return 0;
}
