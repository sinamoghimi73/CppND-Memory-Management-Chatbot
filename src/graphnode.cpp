#include "graphnode.h"

#include <iostream>

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

void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
  /// Since the edge was a Unique Smart_ptr
  _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

//// (DONE!)
void GraphNode::MoveChatbotHere(ChatBot &&chatBot) {
  _chatBot = std::move(chatBot);

  /// Update the _chatBot handle inside ChatLogic
  _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// (DONE!)
  /// Since _childEdges were of kind Unique Smart_ptr we use "get" method.
  return _childEdges[index].get();
}