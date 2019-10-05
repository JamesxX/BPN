#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>
#include <NeuralNetwork/public/neuron.hpp>

#include <stdexcept>
#include <numeric>

using Neuron = NeuralNetwork_ns::Neuron;

NeuralNetwork_ns::output_t Neuron::calculateOutput(NeuralNetwork_ns::output_list_t& input)
{
	return m_ActivationFunction(_STD inner_product(input.begin(), input.end(), m_Weights.begin(), m_Bias));
}

NeuralNetwork_ns::synapse_list_t Neuron::GetWeights()
{
	return m_Weights;
}

void Neuron::SetWeights(NeuralNetwork_ns::synapse_list_t input)
{
	m_Weights = input;
}

NeuralNetwork_ns::weight_t Neuron::GetWeight(NeuralNetwork_ns::neuron_id_t synapseID)
{
	if (synapseID > m_Weights.size())
		throw new _STD range_error("Attempt to GET weight of synapse where synapseID is greater than size of m_Weights!");

	return m_Weights[synapseID];
}

void Neuron::SetWeight(NeuralNetwork_ns::neuron_id_t synapseID, NeuralNetwork_ns::weight_t input)
{
	if (synapseID > m_Weights.size())
		throw new _STD range_error("Attempt to SET weight of synapse where synapseID is greater than size of m_Weights!");

	m_Weights[synapseID] = input;
}

NeuralNetwork_ns::bias_t Neuron::GetBias()
{
	return m_Bias;
}

void Neuron::SetBias(NeuralNetwork_ns::bias_t input)
{
	m_Bias = input;
}