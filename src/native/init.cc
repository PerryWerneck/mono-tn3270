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
 * Este programa está nomeado como init.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include "private.h"

/*---[ Implement ]----------------------------------------------------------------------------------*/

 std::string tn3270_lasterror = "";

/**
 * @brief Cria uma sessão tn3270.
 *
 * @param name	Nome da janela ou "" para criar uma sessão oculta.
 *
 * @return Identificador da sessão criada.
 *
 */
 h3270::session * tn3270_create_session(const char *name) {

 	trace_to_file("%s(%s)",__FUNCTION__,name ? name : "");

 	try {
		return h3270::session::create(name);
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
		trace_to_file("%s(%s)",__FUNCTION__,e.what());
 	}
 	return nullptr;
 }

 /**
  * @brief Destrói uma sessão.
  *
  */
 int tn3270_destroy_session(h3270::session *ses) {

 	trace_to_file("%s",__FUNCTION__);

 	try {
		delete ses;
 	} catch(std::exception &e) {
 		tn3270_lasterror = e.what();
 		return -1;
 	}
	return 0;
 }

#ifdef ENABLE_TRACE_TO_FILE
 void write_trace(const char *fmt, ...) {

	FILE *trace = fopen(PACKAGE_NAME ".trace","a");
	if(trace) {
		va_list arg_ptr;
		va_start(arg_ptr, fmt);
		vfprintf(trace, fmt, arg_ptr);
		fprintf(trace,"\n");
		va_end(arg_ptr);
		fclose(trace);
	}
#ifdef DEBUG
	else {
		perror(PACKAGE_NAME ".trace");
	}
#endif // DEBUG

 }
#endif // ENABLE_TRACE_TO_FILE
