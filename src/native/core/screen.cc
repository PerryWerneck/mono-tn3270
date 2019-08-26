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

 #include <native.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_get_contents(TN3270::Host *ses, char* str, int length) {

	return call(ses,str,length,[](TN3270::Host &ses, int length){

		return ses.toString(0,length);

	});

}

int tn3270_get_string(TN3270::Host *ses, int addr, char* str, int length) {

	return call(ses,str,length,[addr](TN3270::Host &ses, int length){

		return ses.toString(addr,length);

	});


}

int tn3270_get_string_at(TN3270::Host *ses, int row, int col, char* str, int length) {

	return call(ses,str,length,[row,col](TN3270::Host &ses, int length){

		return ses.toString((unsigned int) row, (unsigned int) col, length);

	});

}

int tn3270_set_string_at(TN3270::Host *ses, int row, int col, const char* str) {

	return call(ses,[row,col,str](TN3270::Host &ses){

		ses.push((unsigned int) row, (unsigned int) col, str);
		return 0;

	});


}

int tn3270_wait_for_string_at(TN3270::Host *ses, int row, int col, const char *key, int timeout) {

	return call(ses,[row,col,key,timeout](TN3270::Host &ses){

		ses.wait((unsigned int) row, (unsigned int) col, key, timeout);
		return 0;

	});

}

int tn3270_cmp_string_at(TN3270::Host *ses, int row, int col, const char* str) {

	return call(ses,[row,col,str](TN3270::Host &ses){

		return ses.compare((unsigned int) row, (unsigned int) col, str);

	});

}
