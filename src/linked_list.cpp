#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ < 2){
      return;
    }
    Node* head = front_;
    Node* next_elem = front_->next;
    Node* help_elem = head->next->next;
    while (help_elem != nullptr){
      next_elem->next = head;
      head = next_elem;
      next_elem = help_elem;
      help_elem = help_elem->next;
    }
    next_elem->next = head;
    front_->next = nullptr;
    help_elem = front_;
    front_ = next_elem;
    back_ = help_elem;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ < 2) {
      return;
    }
    LinkedList::reverse_recursive_helper(front_, nullptr);
    Node* help_elem = front_;
    front_ = back_;
    back_ = help_elem;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr->next != nullptr) {
      LinkedList::reverse_recursive_helper(curr->next, curr);
    }
    curr->next = prev;
  }

}  // namespace assignment
