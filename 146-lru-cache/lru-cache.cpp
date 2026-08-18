class LRUCache {
public:

    // Node of doubly linked list
    // Each node stores key, value and pointers to previous/next node
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    // Dummy nodes
    // head -> Most Recently Used
    // tail -> Least Recently Used
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Map stores:
    // key -> address of corresponding node
    unordered_map<int, Node*> m;

    int limit;


    // Adds a node immediately after head
    // Therefore, the node becomes Most Recently Used
    void addNode(Node* newnode) {

        // Store the node currently after head
        Node* oldnext = head->next;

        // Connect head with new node
        head->next = newnode;
        newnode->prev = head;

        // Connect new node with old first node
        newnode->next = oldnext;
        oldnext->prev = newnode;
    }


    // Removes a node from the doubly linked list
    void delNode(Node* oldNode) {

        // Get the nodes before and after oldNode
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;

        // Connect previous node directly to next node
        oldprev->next = oldnext;

        // Connect next node directly to previous node
        oldnext->prev = oldprev;
    }


    LRUCache(int capacity) {

        limit = capacity;

        // Initially list is empty
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {

        // Key doesn't exist in cache
        if (m.find(key) == m.end())
            return -1;

        // Get the node corresponding to key
        Node* ansNode = m[key];

        // Store its value before moving the node
        int ans = ansNode->value;

        // Remove key from map temporarily
        m.erase(key);

        // Remove node from its current position
        delNode(ansNode);

        // Put node at the front
        // It becomes Most Recently Used
        addNode(ansNode);

        // Add it back to map
        m[key] = ansNode;

        return ans;
    }


    void put(int key, int value) {

        // If key already exists
        if (m.find(key) != m.end()) {

            // Get existing node
            Node* oldNode = m[key];

            // Remove old node from linked list
            delNode(oldNode);

            // Remove old key from map
            m.erase(key);
        }


        // If cache is full
        if (m.size() == limit) {

            // tail->prev is the Least Recently Used node
            m.erase(tail->prev->key);

            // Remove LRU node from linked list
            delNode(tail->prev);
        }


        // Create new node
        Node* newnode = new Node(key, value);

        // Add new node at front
        // It becomes Most Recently Used
        addNode(newnode);

        // Store node address in map
        m[key] = newnode;
    }
};