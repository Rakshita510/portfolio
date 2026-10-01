# Simple Line Editor - Help

## Available Commands

### 1. insert

Adds a new line at the specified line number.

**Usage:**

    insert

The editor will ask for:
- Line number
- Text to insert

**Example:**

    > insert
    Enter line number: 1
    Enter text: Hello
    Line inserted successfully.

---

### 2. delete

Deletes a line from the document.

**Usage:**

    delete

The editor will ask for the line number.

**Example:**

    > delete
    Enter line number to delete: 1
    Line deleted successfully.

---

### 3. display

Displays all lines in the current document with their line numbers.

**Usage:**

    display

**Example:**

    > display
    ----- DOCUMENT -----
    1: Hello
    2: Welcome
    --------------------

---

### 4. save

Saves the current document to a text file.

**Usage:**

    save

The editor will ask for a filename.

**Example:**

    > save
    Enter filename: notes.txt
    File saved successfully.

---

### 5. load

Loads a previously saved text file into the editor.

**Usage:**

    load

The editor will ask for a filename.

**Example:**

    > load
    Enter filename: notes.txt
    File loaded successfully.

---

### 6. search

Searches the document for a word or phrase and displays the line numbers where it is found.

**Usage:**

    search

**Example:**

    > search
    Enter word or phrase to search: hello
    ----- SEARCH RESULTS -----
    Found on line 1: hello
    --------------------------

If the word is not present:

    Text not found.

---

### 7. help

Displays all available commands.

**Usage:**

    help

**Example:**

    > help

---

### 8. exit

Closes the Simple Line Editor.

**Usage:**

    exit

**Example:**

    > exit
    Goodbye!

## Summary

| Command | Purpose |
|---|---|
| `insert` | Add a new line |
| `delete` | Delete a line |
| `display` | Display the document |
| `save` | Save the document |
| `load` | Load a saved document |
| `search` | Search for a word or phrase |
| `help` | Show available commands |
| `exit` | Exit the editor |