class MaxHeap {
  #heap = [];

  constructor() {}

  push(value) {
    this.#heap.push(value);
    this.#heapifyUp();
  }

  pop() {
    if (this.#heap.length === 0) return null;

    const maxValue = this.#heap[0];
    this.#heap[0] = this.#heap.pop();
    this.#heapifyDown(0);

    return maxValue;
  }

  top() {
    if (this.#heap.length === 0) return null;

    const maxValue = this.#heap[0];

    return maxValue;
  }

  #heapifyUp() {
    let currentIndex = this.#heap.length - 1;

    while (currentIndex > 0) {
      const parentIndex = Math.floor((currentIndex - 1) / 2);

      if (this.#heap[currentIndex] > this.#heap[parentIndex]) {
        [this.#heap[currentIndex], this.#heap[parentIndex]] = [
          this.#heap[parentIndex],
          this.#heap[currentIndex],
        ];

        currentIndex = parentIndex;
      } else {
        break;
      }
    }
  }

  #heapifyDown(index) {
    let currentIndex = index;

    while (true) {
      const leftChildIndex = 2 * currentIndex + 1;
      const rightChildIndex = 2 * currentIndex + 2;
      let largestChildIndex = currentIndex;

      if (
        leftChildIndex < this.#heap.length &&
        this.#heap[leftChildIndex] > this.#heap[largestChildIndex]
      ) {
        largestChildIndex = leftChildIndex;
      }

      if (
        rightChildIndex < this.#heap.length &&
        this.#heap[rightChildIndex] > this.#heap[largestChildIndex]
      ) {
        largestChildIndex = rightChildIndex;
      }

      if (currentIndex !== largestChildIndex) {
        [this.#heap[currentIndex], this.#heap[largestChildIndex]] = [
          this.#heap[largestChildIndex],
          this.#heap[currentIndex],
        ];
        currentIndex = largestChildIndex;
      } else {
        break;
      }
    }
  }
}
