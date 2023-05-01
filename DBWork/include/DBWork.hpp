class DBWork{
private:
    DBConnection dbConnection;
public:
    std::pair<std::string, std::vector<std::string>> select (std::string sql);
    void update (std::string sql);
    std::hex insert (std::string sql);    
};