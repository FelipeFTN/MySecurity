<template>
  <div class="instance">
    <span>{{ name }}</span><br>
    <span>{{ ip }}</span><br>
    <button @click="shutdown()">Shutdown</button>
    <input type="text" placeholder="Instance Output" readonly/><br>
  </div>
</template>

<script>

export default {
  name: 'Instance',
  props: {
    name: String,
    ip: String,
  },
  methods: {
    shutdown() {
      console.log("Shutdown!");
    },
  },
};
</script>

<style scoped>
.instance {
  width: 12.6rem;
  margin: 0 auto;
  height: 100%;
  border: 1px solid #e1e1e1;
  padding: 10px 10px 10px 10px;
}
</style>