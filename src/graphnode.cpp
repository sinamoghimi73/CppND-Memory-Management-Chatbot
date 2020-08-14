#include "graphnode.h"

#include <iostream>
#include <memory>

#include "chatlogic.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// (DONE!)
  /// Since the chatBot is on the stack
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

/// Made edge as a uninque pointer
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  /// Since the edge was a Unique Smart_ptr
  _childEdges.push_back(std::move(edge));
}

//// (DONE!)
/// removed the reference to chatbot!
void GraphNode::MoveChatbotHere(ChatBot chatBot) {
  _chatBot = std::move(chatBot);
  /// Update the _chatBot handle inside ChatLogic
  _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  /// using move constructor
  newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// (DONE!)
  /// Since _childEdges were of kind Unique Smart_ptr we use "get" method.
  return _childEdges[index].get();
}