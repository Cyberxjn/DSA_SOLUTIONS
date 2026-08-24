class BrowserHistory {
public:
    struct Node {
        string url;
        Node* prev;
        Node* next;

        Node(string u) {
            url = u;
            prev = NULL;
            next = NULL;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        curr->next = newNode;
        newNode->prev = curr;

        curr = newNode;
    }

    string back(int steps) {
        while (steps > 0 && curr->prev != NULL) {
            curr = curr->prev;
            steps--;
        }

        return curr->url;
    }

    string forward(int steps) {
        while (steps > 0 && curr->next != NULL) {
            curr = curr->next;
            steps--;
        }

        return curr->url;
    }
};