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

	std::string contents = ses->get_contents();

	memset(str,0,sz);
	strncpy(str,contents.c_str(),sz);
	if(contents.size() < ((size_t) sz)) {
		str[contents.size()] = 0;
		return contents.size();
	}

	return sz;

}

int tn3270_get_string(h3270::session *ses, int addr, char* str, int strlen) {
	memset(str,0,strlen);
	strncpy(str,ses->get_string(addr,strlen).c_str(),strlen);
	return 0;
}

int tn3270_get_string_at(h3270::session *ses, int row, int col, char* str, int sz) {
	memset(str,0,sz+1);
	strncpy(str,ses->get_string_at(row,col,sz).c_str(),sz);
	return (int) strlen(str);
}

int tn3270_set_string_at(h3270::session *ses, int row, int col, const char* str) {
	debug("%s(%d,%d,\"%s\")",__FUNCTION__,row,col,str);
	ses->set_string_at(row,col,str);
	return 0;
}

int tn3270_wait_for_string_at(h3270::session *ses, int row, int col, const char *key, int timeout) {
	return ses->wait_for_string_at(row,col,key,timeout);
}

int tn3270_cmp_string_at(h3270::session *ses, int row, int col, const char* str) {
	return ses->cmp_string_at(row,col,str);
}
