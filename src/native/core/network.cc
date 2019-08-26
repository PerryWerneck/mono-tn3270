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
 * Este programa está nomeado como network.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include <native.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

int tn3270_connect(TN3270::Host *ses, const char *url, time_t timeout) {

	return call(ses,[url,timeout](TN3270::Host &ses){

		ses.connect(url);

		if(timeout) {
			ses.waitForReady(timeout);
		}

		return 0;

	});

}

int tn3270_disconnect(TN3270::Host *ses) {

	return call(ses,[](TN3270::Host &ses){

		ses.disconnect();
		return 0;

	});

}

int tn3270_is_connected(TN3270::Host *ses) {

	return call(ses,[](TN3270::Host &ses){

		return (ses.isConnected() ? 1 : 0);

	});

}

int tn3270_is_ready(TN3270::Host *ses) {

	return call(ses,[](TN3270::Host &ses){

		return (int) (ses.isReady() ? 1 : 0);

	});

}

int tn3270_wait_for_ready(TN3270::Host *ses, int seconds) {

	return call(ses,[seconds](TN3270::Host &ses){

		ses.waitForReady(seconds);
		return 0;

	});

}

int tn3270_wait(TN3270::Host *ses, int seconds) {

	return call(ses,[seconds](TN3270::Host &ses){

		ses.wait(seconds);
		return 0;

	});

}

