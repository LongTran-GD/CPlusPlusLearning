string time_to_string()
{

    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "_%d_%m_%Y___%H_%M_%S", timeinfo);
    std::string str(buffer);

    return str;
}
