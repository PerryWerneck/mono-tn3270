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
 * Este programa está nomeado como screen.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include "private.h"

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_get_contents(TN3270::Session *ses, char* str, int sz) {

	if(!ses) {
		return -1;
	}

	try {

		std::string contents = ses->toString(0,sz);

		memset(str,0,sz);
		strncpy(str,contents.c_str(),sz);
		if(contents.size() < ((size_t) sz)) {
			str[contents.size()] = 0;
			return contents.size();
		}

	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}

	return sz;

}

int tn3270_get_string(TN3270::Session *ses, int addr, char* str, int strlen) {

	if(!ses) {
		return -1;
	}

	try {
		memset(str,0,strlen);
		strncpy(str,ses->toString(addr,(size_t) strlen).c_str(),strlen);
	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}

	return 0;
}

int tn3270_get_string_at(TN3270::Session *ses, int row, int col, char* str, int length) {

	if(!ses) {
		return -1;
	}

	try {

		memset(str,0,length);
		strncpy(str,ses->toString(row,col,(size_t) length).c_str(),length);

	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return (int) strlen(str);
}

int tn3270_set_string_at(TN3270::Session *ses, int row, int col, const char* str) {

	if(!ses) {
		return -1;
	}

	try {

		ses->push(row,col,str);

	} catch(const exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return 0;
}

int tn3270_wait_for_string_at(TN3270::Session *ses, int row, int col, const char *key, int timeout) {

	if(ses) {

		try {

			return ses->wait(row,col,key,timeout);

		} catch(const exception &e) {

			tn3270_lasterror = e.what();

		}

	}

	return -1;

}

int tn3270_cmp_string_at(TN3270::Session *ses, int row, int col, const char* str) {

	if(ses) {

		try {
			return ses->compare(row,col,str,strlen(str));
		} catch(const exception &e) {
			tn3270_lasterror = e.what();
		}

	}

	return -1;
}
