#include "liboai.h"

class RequestGPT {
public:
  RequestGPT(std::string key, std::string model, std::string requestText)
    : Key(key), Model(model), RequestText(requestText) {}
  std::string Key;
  std::string Model;
  std::string RequestText;
  std::string Response;

  std::string GetResponce() const { return Response; }
  
  void RunRequest() {
    liboai::OpenAI OpenAI;
    liboai::Conversation Conversation;
    Conversation.AddUserData(RequestText);
    bool flag = OpenAI.auth.SetKey(Key);
    if (flag) {
      liboai::Response response = OpenAI.ChatCompletion->create(Model, Conversation);
      Conversation.Update(response);  
      Response = Conversation.GetLastResponse();
    }
  }
};

class ContentCheck {
private:
  void Check() {
    std::string key = "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";
    std::string model = "gpt-3.5-turbo";
    RequestGPT gpt(key, model, Content + Responce);
    gpt.RunRequest();
    // PercentOfUnacceptable = std::stoi(gpt.GetResponce());
    std::cout << gpt.GetResponce() << std::endl;
  }
public:
  ContentCheck(std::string content) : Content(content) {};
  std::string Content;
  int PercentOfUnacceptable;
  const std::string Responce = " - содержит ли этот текст в себе слова 18+. Напиши 1, если да или 0, если нет без знаков препинания";
  bool isUnacceptable() {
    Check();
    if (PercentOfUnacceptable >= 5) {
      return true;
    } else {
      return false;
    }
  }
};

// int main() {
//   ContentCheck cc("Я Крис,мне уже 19,в этом году 20,ищу друзей,а так как будет ( в плане пацанов) Не хватет общения,я работаю,учусь,гулять некогда,зз-близнецы Все остальное узнаете в лс");
//   std::cout << cc.isUnacceptable();

// }