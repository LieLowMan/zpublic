#include "server_config.h"
#include "game_common/config/config_manager.h"
#include "game_common/path_definition.h"

bool ServerConfig::parse()
{
    Json::Value value;
    LOAD_CONFIG(ConfigFile::ServerConfig, value);

    phpServerAddress = value["global"]["php_server_address"].asString();

    Json::Value& gameServiceValue = value["server"]["game_service"];
    if (gameServiceValue != Json::nullValue)
    {
        serviceName = gameServiceValue["service_name"].asString();
        listenAddress = gameServiceValue["listen_address"].asString();
        maxQueued = gameServiceValue["max_queued"].asInt();
        maxThreads = gameServiceValue["max_threads"].asInt();
        sqlite3File = gameServiceValue["sqlite3_file"].asString();
        mysql_server = gameServiceValue["mysql_server"].asString();
        mysql_database = gameServiceValue["mysql_database"].asString();
        mysql_user = gameServiceValue["coeus_game"].asString();
        mysql_password = gameServiceValue["coeus_game"].asString();
    }
    else
    {
        return false;
    }

	return true;
}
