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

 #include <native.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

 static int action(TN3270::Host *ses, std::function<void(TN3270::Host &ses)> worker) noexcept {

 	try {

		if(!ses->isConnected()) {
			tn3270_lasterror = "Not connected";
		}

		worker(*ses);
		return 0;

	} catch(const std::system_error &e) {

		tn3270_set_error(ses,e);

	} catch(const std::exception &e) {

		tn3270_set_error(ses,e);

	} catch(...) {

		tn3270_set_error(ses,"Unexpected error");

	}

	return -1;

 }


static int action(TN3270::Host *ses, TN3270::Action id) noexcept {

	return action(ses, [id](TN3270::Host &ses) {
		ses.push(id);
	});

}

int tn3270_pfkey(TN3270::Host *ses, int key) {

	return action(ses, [key](TN3270::Host &ses) {
		ses.pfkey(key);
	});

}

int tn3270_pakey(TN3270::Host *ses, int key) {

	return action(ses, [key](TN3270::Host &ses) {
		ses.pakey(key);
	});

}

int tn3270_action(TN3270::Host *ses, const char *name) {

	return action(ses, [name](TN3270::Host &ses) {
		ses.action(name);
	});

}

int tn3270_enter(TN3270::Host *ses) {
	return action(ses,TN3270::ENTER);
}

int tn3270_erase(TN3270::Host *ses) {
	return action(ses,TN3270::ERASE);
}

int tn3270_erase_eof(TN3270::Host *ses) {
	return action(ses,TN3270::ERASE_EOF);
}

int tn3270_erase_eol(TN3270::Host *ses) {
	return action(ses,TN3270::ERASE_EOL);
}

int tn3270_erase_input(TN3270::Host *ses) {
	return action(ses,TN3270::ERASE_INPUT);
}

