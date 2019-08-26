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
 * Este programa está nomeado como - e possui - linhas de código.
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
 * @author perry.werneck@gmail.com
 *
 */

 #include <getopt.h>
 #include <cstdlib>
 #include <native.h>

 using namespace std;

/*---[ Implement ]----------------------------------------------------------------------------------*/


/*
 // test host object
 static void testHost(const char *session) {

	TN3270::Host host{session,nullptr,10};

	try {

		cout
			<< "Version: " << host.getVersion()
			<< "\tRevision: " << host.getRevision()
			<< std::endl;

		host.connect(nullptr);

		cout
			<< "Wait for unlock returns " << host.getKeyboardLockState() << std::endl
			<< "Connection state is " << toCharString(host.getConnectionState()) << std::endl
			<< "Program message is " << toCharString(host.getProgramMessage()) << std::endl
			<< "Luname is " << host.getLUName() << std::endl
			<< std::endl;

		if(host) {
			cout << host << endl;
		}

		host.setCursor(10,10);

		host.wait(10);

		// host.input("test@0another line");

		host.push(TN3270::ENTER);

		cout << endl << "[" << host.toString((unsigned int) 1, (unsigned int) 3,7) << "]" << endl;
		cout << endl << "[" << host.toString((int) 15, (int) 10) << "]" << endl;

		host.pfkey(3);

		host.wait(10);

		host.disconnect();

	} catch(const std::exception &e) {

		cerr << std::endl << e.what() << std::endl << std::endl;

	}

 }
 */

 int main(int argc, char **argv) {

	const char * session = ""; // "pw3270:a";
	char buffer[4096];

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
	static struct option options[] = {
		{ "session",	required_argument,	0,	's' },
		{ 0, 0, 0, 0}

	};
	#pragma GCC diagnostic pop

	int long_index =0;
	int opt;
	while((opt = getopt_long(argc, argv, "s:", options, &long_index )) != -1) {

		switch(opt) {
		case 's':
			session = optarg;
			break;

		}

	}

	cout << "Session:  " << session << endl;

	TN3270::Host * host = tn3270_create_session(session);

	tn3270_get_version(host,buffer,sizeof(buffer));
	cout << "Version:  " << buffer << endl;

	tn3270_get_revision(host,buffer,sizeof(buffer));
	cout << "Revision: " << buffer << endl;

	tn3270_connect(host,nullptr,10);

	cout	<< "Connection state is " << tn3270_get_cstate(host) << std::endl
			<< "Program message is " << tn3270_get_program_message(host) << std::endl;

	tn3270_get_contents(host,buffer,sizeof(buffer));
	cout << buffer << endl;

	tn3270_set_cursor_position(host,10,10);
	tn3270_wait(host,10);

	tn3270_enter(host);
	tn3270_wait_for_ready(host,10);

	tn3270_get_contents(host,buffer,sizeof(buffer));
	cout << buffer << endl;

	tn3270_pfkey(host,3);
	tn3270_wait_for_ready(host,10);

	tn3270_get_contents(host,buffer,sizeof(buffer));
	cout << buffer << endl;

	tn3270_disconnect(host);

	tn3270_destroy_session(host);

	return 0;
 }


