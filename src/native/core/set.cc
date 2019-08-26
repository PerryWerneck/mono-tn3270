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

 #include <native.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_set_unlock_delay(TN3270::Host *ses, int ms) {

	return call(ses,[ms](TN3270::Host &ses) {

		ses.setUnlockDelay(ms);
		return 0;

	});

}

int tn3270_set_cursor_position(TN3270::Host *ses, int row, int col) {

	return call(ses,[row,col](TN3270::Host &ses) {

		ses.setCursor((unsigned short) row, (unsigned short) row);
		return 0;

	});


}

int tn3270_set_cursor_addr(TN3270::Host *ses, int addr) {

	return call(ses,[addr](TN3270::Host &ses) {

		ses.setCursor(addr);
		return 0;

	});

}

int tn3270_set_charset(TN3270::Host *ses, const char* str) {

	return call(ses,[str](TN3270::Host &ses) {

		ses.setCharSet(str);
		return 0;

	});

}

int tn3270_set_url(TN3270::Host *ses, const char *url) {

	return call(ses,[url](TN3270::Host &ses) {

		ses.setHostURL(url);
		return 0;

	});
}

