#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>

#include <string>

class GraphNode;  // forward declaration
class ChatLogic;  // forward declaration

class ChatBot {
 private:
  // data handles (owned)
  wxBitmap *_image;  // avatar image

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  int _count;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

 public:
  // constructors / destructors
  ChatBot(int count = 0);  // constructor WITHOUT memory allocation
  ChatBot(std::string filename,
          int count = 0);  // constructor WITH memory allocation
  ~ChatBot();

  //// (Done!)
  /// Rule of Five Implemented!
  /// Copy Constructor
  ChatBot(const ChatBot &src);

  /// Copy Assignment
  ChatBot &operator=(const ChatBot &src);

  /// Move Constructor
  ChatBot(ChatBot &&src);

  /// Move Assignment
  ChatBot &operator=(ChatBot &&src);

  /// GetChatLogicHandle Added!
  ChatLogic *GetChatLogicHandle() { return _chatLogic; }

  // getters / setters

  /// An Arbitrary function to update current Node!
  void UpdateCurrentNode(GraphNode *currentNode) { _currentNode = currentNode; }

  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);

  // updating chatbot count
  void Increase();
  void Decrease();
};

#endif /* CHATBOT_H_ */
