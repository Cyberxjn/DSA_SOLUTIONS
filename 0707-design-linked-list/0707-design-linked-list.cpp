class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;

        for (int i = 0; i < index; i++) {
            if (temp == NULL)
                return -1;

            temp = temp->next;
        }

        if (temp == NULL)
            return -1;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            if (temp == NULL)
                return;

            temp = temp->next;
        }

        if (temp == NULL)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == NULL)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            if (temp == NULL)
                return;

            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
            return;

        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;
    }
};