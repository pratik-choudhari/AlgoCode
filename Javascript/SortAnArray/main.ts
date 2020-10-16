function main() {
    const n: number = Number(prompt("Number of elements (N):"));
    const arr: number[] = prompt("Insert the number sequence:")
                            .split(" ")
                            .map(val => Number(val));
    
    const sortedArr: number[] = specialSort(n, arr);
    
    alert(`Sorted sequence : \n${sortedArr}`);
}

/**
 * Splits a number array in half proceeding to sort the first half in
 * ascending order and the second half in descending order, merging
 * both in the end.
 * @param {number} n - The length of the given array.
 * @param {number[]} arr - The array to be sorted.
 * @returns {number[]} - The specially sorted array.
 */
function specialSort(n: number, arr: number[]): number[] {
    const ascArr: number[] = new SortedList(arr.slice(0, ~~n/2)).get();
    const descArr: number[] = new SortedList(arr.slice(~~n/2), true).get();
    return ascArr.concat(descArr);
}

class SortedList {
    readonly arr: number[];
    readonly reverse: boolean;
    n: number;

    /**
     * Constructs a SortedList object and sorts it.
     * @param {number[]} arr - The array to be sorted.
     * @param {boolean} reverse - Whether to sort the array in
     * ascending order (false) or descending order (true).
     */
    constructor(arr: number[], reverse: boolean = false) {
        this.arr = arr;
        this.n = arr.length;
        this.reverse = reverse;
        this.sort();
    }

    /**
     * Sorts the array in ascending or descending order, according
     * to the {this.reverse} value.
     */
    sort() {
        if (this.n === 1) return;

        for (let i = 0, j = 1; i < this.n - 1; i++, j++){
            if ((this.reverse) ?  
                    this.arr[i] < this.arr[j] : 
                    this.arr[i] > this.arr[j]) {
                this.swapElements(i, j);
                ;
            }
        }
        this.n--;
        
        this.sort();
    }

    /**
     * Swaps two elements of the array.
     * @param {number} iA - Index of element A.
     * @param {number} iB - Index of element B.
     */
    swapElements(iA: number, iB: number) {
        const cursor = this.arr[iA];
        this.arr[iA] = this.arr[iB];
        this.arr[iB] = cursor;
    }

    /**
     * Get the Sorted Array.
     * @returns {number[]} - The sorted array.
     */
    get(): number[] {
        return this.arr;
    }
}