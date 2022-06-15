const ref = require('ref-napi')
const ar = require('ref-array-di')
const { exampleInput } = require('./build/Release/example')

const ArrayType = ar(ref)
const ArrayFloat = ArrayType(ref.types.float)

// this is an example js-space wrapper with an ArrayFloat input
function exampleInputWrapped (aInput) {
  const ia = typeof aInput.ref === 'function' ? aInput : new ArrayFloat(aInput)
  return exampleInput(ia)
}

// make a new one
// you can also use an int for length, for empty array
const a = new ArrayFloat([0, 0, 0, 0])

// just some nice floats
a[0] = Math.PI
a[1] = Math.LN2
a[2] = Math.E
a[3] = Date.now() / 1000

// gets you the underlying buffer-store, if you need that
console.log(a.ref())

// gets you the actual memory address
console.log(a.ref().address())

// this will pass the pointer
console.log(exampleInputWrapped(a))

// this will less effienctly make a new ArrayFloat and pass it
console.log(exampleInputWrapped([1, 2, 3, 4]))
