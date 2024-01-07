import React from 'react'
import { SafeAreaView, StyleSheet, View, Text, Image } from "react-native";

function Register() {
  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.boxInfo}>
        <Text>Register</Text>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container:{
    flex:1,
    backgroundColor:"#000",

  },
  background: {
    width:"100%",
    height:"100%",

  },
});


export default Register;

