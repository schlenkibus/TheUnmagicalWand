#include <iostream>
#include <SFML/Network.hpp>

void startServer();

bool running = true;

int main()
{
	startServer();
	return 0;
}

void startServer()
{
	sf::TcpListener listener;
	listener.listen(55001);
	while(running)
	{
		sf::TcpSocket client;
		if(listener.accept(client) == sf::Socket::Done)
		{
			std::cout << "new connection from " << client.getRemoteAdress() << std::endl;
			sf::Packet pack;
			while(listener.recieve(pack) != sf::Socket::Done)
			{
				std::cout << "waiting for package!" << std::endl;
			}
			int rating;
			if(pack >> rating)
			{
				//Success!
				std::cout << "rated: " << rating << std::endl;
			}
			listener.
		}
	}
}