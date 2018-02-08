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

int tn3270_get_contents(h3270::session *ses, char* str, int sz) {

	try {

		std::string contents = ses->get_contents();

		memset(str,0,sz);
		strncpy(str,contents.c_str(),sz);
		if(contents.size() < ((size_t) sz)) {
			str[contents.size()] = 0;
			return contents.size();
		}

	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}

	return sz;

}

int tn3270_get_string(h3270::session *ses, int addr, char* str, int strlen) {

	try {
		memset(str,0,strlen);
		strncpy(str,ses->get_string(addr,strlen).c_str(),strlen);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}

	return 0;
}

int tn3270_get_string_at(h3270::session *ses, int row, int col, char* str, int sz) {
	try {
		memset(str,0,sz+1);
		strncpy(str,ses->get_string_at(row,col,sz).c_str(),sz);
		trace_to_file("%s(%d,%d,%d):\n%s\n",__FUNCTION__,row,col,sz,str);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return (int) strlen(str);
}

int tn3270_set_string_at(h3270::session *ses, int row, int col, const char* str) {
	try {
		trace_to_file("%s(%d,%d):\n%s\n",__FUNCTION__,row,col,str);
		debug("%s(%d,%d,\"%s\")",__FUNCTION__,row,col,str);
		ses->set_string_at(row,col,str);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
		return -1;
	}
	return 0;
}

int tn3270_wait_for_string_at(h3270::session *ses, int row, int col, const char *key, int timeout) {
	try {
		return ses->wait_for_string_at(row,col,key,timeout);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
	}
	return -1;

}

int tn3270_cmp_string_at(h3270::session *ses, int row, int col, const char* str) {
	try {
		return ses->cmp_string_at(row,col,str);
	} catch(std::exception &e) {
		tn3270_lasterror = e.what();
	}
	return -1;
}
