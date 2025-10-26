# DocumentManager – Design & Testing

## Data Structures & Rationale
- `unordered_map<int, Document>`: O(1) avg access to documents by id.
- `unordered_map<string, int>`: O(1) avg name → id for `search`.
- `unordered_set<int>`: O(1) avg membership to validate patrons.
- `unordered_map<int, unordered_set<int>>`: O(1) avg to track a patron’s borrowed docs and prevent double-borrows.

This avoids linear scans; supports millions of docs/patrons.

## API Semantics
- `search(name)`: returns docid or **0** if absent.
- `borrowDocument(docid, patronID)`: returns **true** iff patron & doc exist, license not full, and patron doesn’t already hold the doc.
- `returnDocument(docid, patronID)`: safe no-op if invalid or not held.

## Complexity
| Operation             | Average Time |
|----------------------|--------------|
| addDocument          | O(1)         |
| addPatron            | O(1)         |
| search(name)         | O(1)         |
| borrowDocument       | O(1)         |
| returnDocument       | O(1)         |

## Edge Cases Covered
- Duplicate patrons/docs (idempotent).
- Borrow at license limit → false.
- Same patron borrowing same doc twice → false.
- Returning unheld/invalid → no crash; counts never negative.

## Build & Run
```bash
g++ -std=c++17 -O2 -Wall -Wextra tests.cpp -o run
./run