class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

# Fungsi untuk menyisipkan node ke BST
def insert(root, key):
    if root is None:
        return Node(key)
    elif key < root.val:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

# Fungsi untuk traversal inorder (cetak urut dari kecil ke besar)
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

# Fungsi untuk mencari nilai minimum dari subtree (digunakan saat delete)
def minValueNode(node):
    current = node
    while current.left:
        current = current.left
    return current

# Fungsi untuk menghapus node dari BST
def deleteNode(root, key):
    if root is None:
        return root
    if key < root.val:
        root.left = deleteNode(root.left, key)
    elif key > root.val:
        root.right = deleteNode(root.right, key)
    else:
        # Node dengan satu atau tanpa anak
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        # Node dengan dua anak
        temp = minValueNode(root.right)
        root.val = temp.val
        root.right = deleteNode(root.right, temp.val)
    return root

# --- Main Program ---

# Langkah 1: Buat BST dari T
T = [1, 4, 5, 6, 11, 12, 20]
root = None
for val in T:
    root = insert(root, val)

# Langkah 2: Hapus nilai 6
root = deleteNode(root, 6)

# Langkah 3: Tam
