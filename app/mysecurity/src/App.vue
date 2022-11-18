<script setup>
</script>

<template>
  <div class="container">
    <h1>MySecurity</h1>
    <Instance name="MyInstance" ip="127.0.0.1" />
  </div>
</template>

<script>
import Instance from "./components/Instance.vue";

export default {
  name: 'App',
  components: {
    Instance,
  },
};
</script>


<style scoped>
.container {
	margin: auto;
	text-align: center;
	display: flex;
	flex-direction: column;
	justify-content: center;
	align-items: center
}
</style>
