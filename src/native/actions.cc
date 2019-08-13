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
 * Este programa está nomeado como actions.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 /**
  * @file actions.cc
  *
  * @brief Actions wrapper.
  *
  * @author Perry Werneck <perry.werneck@gmail.com>
  *
  */

 #include "private.h"

/*---[ Implement ]----------------------------------------------------------------------------------*/

static int do_action(TN3270::Session *ses, TN3270::Action action) {

	if(ses) {

		try {

			ses->push(action);
			return 0;

		} catch(const exception &e) {

			tn3270_lasterror = e.what();
			return -1;

		}

	}

	return -1;

}

int tn3270_enter(TN3270::Session *ses) {
	return do_action(ses,TN3270::ENTER);
}

int tn3270_pfkey(TN3270::Session *ses, int key) {

	try {

		ses->pfkey(key);
		return 0;

	} catch(const exception &e) {

		tn3270_lasterror = e.what();

	}
	return -1;

}

int tn3270_pakey(TN3270::Session *ses, int key) {

	try {

		ses->pakey(key);
		return 0;

	} catch(const exception &e) {

		tn3270_lasterror = e.what();

	}
	return -1;
}

int tn3270_action(TN3270::Session *ses, const char *name) {

	try {

		ses->action(name);
		return 0;

	} catch(const exception &e) {

		tn3270_lasterror = e.what();

	}
	return -1;

}

int tn3270_erase(TN3270::Session *ses) {
	return do_action(ses,TN3270::ERASE);
}

int tn3270_erase_eof(TN3270::Session *ses) {
	return do_action(ses,TN3270::ERASE_EOF);
}

int tn3270_erase_eol(TN3270::Session *ses) {
	return do_action(ses,TN3270::ERASE_EOL);
}

int tn3270_erase_input(TN3270::Session *ses) {
	return do_action(ses,TN3270::ERASE_INPUT);
}

