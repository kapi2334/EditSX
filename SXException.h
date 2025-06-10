namespace sxEditCore{
    class SXException: public std::exception{
        private:
            std::string message;
        public:
            SXException(const std::string& msg){
                message = msg;
            }
        
            const char* what() const noexcept override{
                return message.c_str();
            }
    };

} 
