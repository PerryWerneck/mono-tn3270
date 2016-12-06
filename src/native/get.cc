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
 * Este programa está nomeado como get.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

 #include "private.h"


/*---[ Implement ]----------------------------------------------------------------------------------*/

 /**
  * @brief Obtém a versão da biblioteca.
  *
  */
 void tn3270_get_version(h3270::session *ses, char* str, int strlen) {
 	strncpy(str,ses->get_version().c_str(),strlen);
 }

 /**
  * @brief Obtém a revisão da biblioteca.
  *
  */
 void tn3270_get_revision(h3270::session *ses, char* str, int strlen) {
	strncpy(str,ses->get_revision().c_str(),strlen);
 }

 int tn3270_get_cstate(h3270::session *ses) {
	return (int) ses->get_cstate();
 }

 int tn3270_get_program_message(h3270::session *ses) {
	return (int) ses->get_program_message();
 }

 int tn3270_get_secure(h3270::session *ses) {
	return (int) ses->get_secure();
 }