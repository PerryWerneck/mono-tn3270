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

 #include "private.h"

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_enter(h3270::session *ses) {
	try {
		return ses->enter();
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_pfkey(h3270::session *ses, int key) {
	try {
		return ses->pfkey(key);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_pakey(h3270::session *ses, int key) {
	try {
		return ses->pakey(key);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_action(h3270::session *ses, const char *name) {
	try {
		return ses->action(name);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_erase(h3270::session *ses) {
	try {
		return ses->erase();
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_erase_eof(h3270::session *ses) {
	try {
		return ses->erase_eof();
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_erase_eol(h3270::session *ses) {
	try {
		return ses->erase_eol();
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

int tn3270_erase_input(h3270::session *ses) {
	try {
		return ses->erase_input();
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
}

