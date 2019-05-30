# 028 Linked list Queue實作 
Queue 需設計成使用 Structure/Class，並使用串列 Link list實作。

## 功能說明： 
### 1. CreateQueue
建立一個Queue，並給予Queue的名稱。  

### 2. EnQueue 
輸入一個Queue的名稱，並插入資料 (int)，若Queue的名稱不存在，則 printf("Queue 名稱 isn't exist", name)。  

### 3. DeQueue 
輸入一個Queue的名稱，並進行 Dequeue。  
若Queue的名稱不存在，則 printf("Queue 名稱 isn't exist", name)。  
若 queue為空，輸出 Queue is empty。  
若沒有錯誤，只需取出數值，不用輸出。  

### 4. MergeQueue 
輸入兩個Queue的名稱Ａ,B，進行QueueA與QueueB相接(B接到A)，連接完畢後，刪除QueueB。  
若Queue的名稱不存在，則printf("Queue 名稱 isn't exist", name)  

### 5. PrintAllQueue 
依序印出所有的Queue, Queue size, Queue element  
printf("\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*");  
printf("Queue Name:名稱 Queue Size:長度 Queue Element:", queue->name, count);  
printf("\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*");  
若不存在任何Queue，則printf(Isn't have any queue);  
如果queue存在，但queue裡面是空的話 要printf("Queue Name:名稱 Queue Size:長度 Queue Element:Queue is empty", queue->name, count);  

### 6. Exit 


## Sample Input: 
1  
AAA  
1  
BBB  
2  
AAA  
1  
2  
AAA  
3  
2  
AAA  
4  
2  
AAA  
5  
2  
AAA  
6  
2  
BBB  
7  
5  
4  
AAA  
BBB  
5  
6  


## Sample Output: 
\****************************************  
Queue Name:AAA Queue Size:5 Queue Element:1 3 4 5 6  
Queue Name:BBB Queue Size:1 Queue Element:7  
\****************************************  
\****************************************  
Queue Name:AAA Queue Size:6 Queue Element:1 3 4 5 6 7  
\****************************************  