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
  * @file
  *
  * @brief
  *
  * @author
  *
  */

 #include <native.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

int call(TN3270::Host *ses, std::function<int(TN3270::Host &ses)> worker) noexcept {

  	if(!ses) {

 		return tn3270_set_error(ses, "Invalid session handle");

 	}

 	try {

		return worker(*ses);

 	} catch(const exception &e) {

 		tn3270_set_error(ses, e);

 	} catch(...) {

 		tn3270_set_error(ses, "Unexpected error");

 	}

	return -1;

}

int call(TN3270::Host *ses, char* str, int length, std::function<string(TN3270::Host &ses, int length)> worker) {

	if(!(str && length)) {

 		return tn3270_set_error(ses, "The output buffer is invalid");

	}

  	if(!ses) {

 		return tn3270_set_error(ses, "Invalid session handle");

 	}

 	try {

		std::string contents = worker(*ses, length);

		memset(str,0,length);
		strncpy(str,contents.c_str(),length);
		if(contents.size() < ((size_t) length)) {
			str[contents.size()] = 0;
			return contents.size();
		}

		return length;

 	} catch(const exception &e) {

 		tn3270_set_error(ses, e);

 	} catch(...) {

 		tn3270_set_error(ses, "Unexpected error");

 	}

	return -1;


}

int tn3270_set_error(TN3270::Host *ses, const char *str) noexcept {
	tn3270_lasterror = str;
	return -1;
}

int tn3270_set_error(TN3270::Host *ses, const std::exception &e) noexcept {
	tn3270_lasterror = e.what();
	return -1;
}


