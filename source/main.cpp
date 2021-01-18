//
// Created by alex on 18/01/2021.
//

#include "main.hpp"

int main() {
	std::string
		token = Env::Get("DISCORD_TOKEN");

	discpp::ClientConfig config({"!"});
	// Make sure to replace `TOKEN HERE` with your actual token
	discpp::Client client{ token, config }; // Token, config

	// For more complex commands, create a class for each one.
	client.command_handler->RegisterCommand<discpp::Command>("ping", "", [](discpp::Context ctx) {
		ctx.Send("Pong!");
	});

	// This notifies you in the console when the client becomes ready to receive and send requests
	client.event_handler->RegisterListener<discpp::ReadyEvent>([&] (const discpp::ReadyEvent& event) {
		client.logger->Info("Ready!");
	});

	return client.Run();
}