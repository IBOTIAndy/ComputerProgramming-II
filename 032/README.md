# binary tree 
�Hdata�j�p���̾ڡA���l��p�󵥩�ڡA�k�l��j��ڡA�إߤG����C  
//���J��ƶi�G����  
(1)void Insert(nodep_t *node, student_t key);  
//���Ǩ��X�L�X�G�����k  
(2)void Inorder(nodep_t *node);  
---------------------

### ��J�����G
p function(2)  
i function(1)  
5 �����J���Ʀr  
p  
i  
6  
p  
i  
7  
p  
i  
3  
p  
i  
4  
p  
e ������J  
------------------------------

### ��X�����G
p (�L�X):  
(1)�S��tree �L�X null  
(2)�Ĥ@�Ӵ��J���Ʀr�� root  
(3)�p��B���� root �����l��  
(4)�j�� root ���k�l��  
3 4 5 6 7 �C��data�������ť�  
----------------------

### Sample Input:
p  
i  
5  
p  
i  
6  
p  
i  
7  
p  
i  
3  
p  
i  
4  
p  
i  
2  
p  
i  
6  
p  
e  
-------------------

### Sample Output:
null  
5  
5 6  
5 6 7  
3 5 6 7  
3 4 5 6 7  
2 3 4 5 6 7  
2 3 4 5 6 6 7  