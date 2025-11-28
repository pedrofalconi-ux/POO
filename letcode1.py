import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
    # Para permitir comparação dentro do heap
    def __lt__(self, other):
        return self.val < other.val


class Solution:
    def mergeKLists(self, lists):
        heap = []
        
        # Insere o primeiro nó de cada lista no heap
        for node in lists:
            if node:
                heapq.heappush(heap, node)
        
        dummy = ListNode(0)
        current = dummy
        
        # Processa o heap até ficar vazio
        while heap:
            smallest = heapq.heappop(heap)
            current.next = smallest
            current = current.next
            
            if smallest.next:
                heapq.heappush(heap, smallest.next)
        
        return dummy.next